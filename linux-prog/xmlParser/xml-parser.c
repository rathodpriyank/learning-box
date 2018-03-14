/*
 * xmlParser.c
 *
 *  Created on: Jun 24, 2017
 *      Author: Priyank Rathod
 */
// System headers
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Xml headers
#include <libxml/xmlreader.h>
#include <libxml/xmlmemory.h>
#include <libxml/xpath.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpathInternals.h>

// local headers
#include "xml-parser.h"

/**
 * @brief Convert the value of a XML attribute to an integer value
 *
 * @param[in] XML attribute
 * @note      Provides a more robust alternative for atoi
 */
static int convertToInt( const char* strval )
{
   char* endval = NULL;

   // Initialize error
   errno = 0;

   int value = strtol( strval, &endval, 10 );

   // Check for error(s)
   if ( (0 != errno) || (strval == endval) )
   {
      MW_ERR("[%s:%d:%s()] Failed to convert value %s to integer\n", __FILE__, __LINE__, __func__, strval );
      return 0;
   }

   return value;
}

/**
 * @brief Retrieves the root node of the power management configuration from xml file
 *
 * @param[in]   XML doc (see libxml2)
 *
 */
static xmlNode* getConfigRoot( xmlDoc* doc, xmlChar* config )
{
   // Get the root node
   xmlNode* root = xmlDocGetRootElement( doc );
   if ( NULL == root )
   {
      MW_ERR("[%s:%d:%s()] Encountered problems while reading configuration from %s ! Please, verify content ... \n",
             __FILE__, __LINE__, __func__, doc->name );

      return NULL;
   }

   // Check the root node
   if ( xmlStrcmp( root->name, config ) )
   {
      MW_ERR("[%s:%d:%s()] Configuration not found in %s ! Expected (%s) and found (%s) ... \n",
             __FILE__, __LINE__, __func__, doc->name, config, root->name );

      return NULL;
   }

   return root;
}

/**
 * @brief Retrieves the power management configuration values from the xml document
 *
 * @param[in]   XML doc (see libxml2)
 * @param[out]  Power management configuration
 *
 */
static void parse( xmlDoc* doc, sampleCfg_t* config )
{
   // Get root
   xmlNode* root = getConfigRoot( doc, (xmlChar*) "sample-config" );
   if ( NULL != root )
   {
      xmlNode* node = root->children;
      for (  ; node != NULL; node = node->next )
      {
         if ( 0 == xmlStrcmp( node->name, (const xmlChar*) "sample1" ) )
         {
            memset(config->sample1, '\0', sizeof(config->sample1));
            memcpy(config->sample1, ( (char*) xmlNodeGetContent(node) ), sizeof(config->sample1));
         }

         if ( 0 == xmlStrcmp( node->name, (const xmlChar*) "sample2" ) )
         {
             memset(config->sample2, '\0', sizeof(config->sample2));
             memcpy(config->sample2, ( (char*) xmlNodeGetContent(node) ), sizeof(config->sample2));
         }

         if ( 0 == xmlStrcmp( node->name, (const xmlChar*) "sample3" ) )
         {
             memset(config->sample3, '\0', sizeof(config->sample3));
             memcpy(config->sample3, ( (char*) xmlNodeGetContent(node) ), sizeof(config->sample3));
         }
		 if ( 0 == xmlStrcmp( node->name, (const xmlChar*) "sample4" ) )
         {
			 config->sample4 = convertToInt( (char*) xmlNodeGetContent(node) );
         }
      }
   }
}

/**
 * @brief  Get the power management configuration from the XML configuration file
 *
 * @param[in]  XML file name
 *
 * @return   power management configuration as set in xml file
 */
sampleCfg_t getConfigurationFromXml( char* sampleXmlDoc )
{
   // Initialize libxml
   xmlInitParser();
   LIBXML_TEST_VERSION

   xmlDoc* configDoc = xmlParseFile( sampleXmlDoc );
   if ( NULL == configDoc )
   {
      MW_ERR("[%s:%d:%s()] Cannot parse file %s ! Please, check whether the file exists ... \n",
             __FILE__, __LINE__, __func__, sampleXmlDoc );

      exit(EXIT_FAILURE);
   }

   sampleCfg_t config;

   // Parse
   parse( configDoc, &config);

   // Clean up
   xmlFreeDoc(configDoc);
   xmlCleanupParser();

   return config;
}

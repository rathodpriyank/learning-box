/*
 * xmlParser.h
 *
 *  Created on: Jun 24, 2017
 *      Author: pj
 */

#ifndef XMLPARSER_H_
#define XMLPARSER_H_

// sample logging format
#define MW_ERR(args...) fprintf(stderr, args);


typedef struct
{
   char sample1[32];
   char sample2[32];
   char sample3[32];
   int sample4;
} sampleCfg_t;


sampleCfg_t getConfigurationFromXml( char* sampleXmlDoc );

#endif /* XMLPARSER_H_ */

/*
 * main.c
 *
 *  Created on: Jun 24, 2017
 *      Author: Priyank Rathod
 */

#include <stdio.h>
#include <stdlib.h>

#include "xml-parser.h"

#define SAMPLE_CFG_FILE   "./sampleXml.xml"

static sampleCfg_t sampleConfig;

int main() {

	sampleConfig = getConfigurationFromXml( SAMPLE_CFG_FILE );
	printf("sampleConfig->sample1 : %s\n", sampleConfig.sample1);
	printf("sampleConfig->sample2 : %s\n", sampleConfig.sample2);
	printf("sampleConfig->sample3 : %s\n", sampleConfig.sample3);
	printf("sampleConfig->sample4 : %d\n", sampleConfig.sample4);
	return EXIT_SUCCESS;
}

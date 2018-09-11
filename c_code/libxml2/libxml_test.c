

#include <stdio.h>
#include <stdlib.h>
#include <libxml/parser.h>
#include <libxml/tree.h>


int parse_npd(xmlNodePtr node);
int parse_flux(xmlNodePtr node);

int main(void)
{
	xmlDocPtr doc = NULL;
	xmlNodePtr node_r = NULL;
	xmlNodePtr node_1 = NULL;
	char* filename = "./test.xml";

	doc = xmlReadFile(filename, "UTF-8", XML_PARSE_RECOVER);
	if (doc == NULL)
	{
		printf("read config file error.\n");
		exit(1);
	}

	node_r = xmlDocGetRootElement(doc);
	if (xmlStrcmp(node_r->name, BAD_CAST "GLOBAL"))
	{
		printf("document of the wrong type, root node != GLOBAL.\n");
		xmlFreeDoc(doc);
		exit(1);
	}

	node_1 = node_r->children;
	while (node_1 != NULL)
	{
		if (!xmlStrcmp(node_1->name, BAD_CAST "NPD"))
		{
			parse_npd(node_1);
			printf("parse_npd()!\n");
		}
		else if (!xmlStrcmp(node_1->name, BAD_CAST "FLUX"))
		{
			parse_flux(node_1);
			printf("parse_flux()!\n");
		}
		node_1 = node_1->next;
	}

	xmlSaveFile("test.xml", doc);
	return 0;
}

int parse_npd(xmlNodePtr node)
{
	xmlChar *content;
	char *content_new = "lov";
	xmlNodePtr node_1 = NULL;
	node_1 = node->children;

	while (node_1 != NULL)
	{
		if (!xmlStrcmp(node_1->name, BAD_CAST "probe_id"))
		{
			content = xmlNodeGetContent(node_1);
			xmlFree(content);
			xmlNodeSetContent(node_1, (xmlChar *)content_new);
		}
		node_1 = node_1->next;
	}
}

int parse_flux(xmlNodePtr node)
{
	xmlChar *content;
	xmlNodePtr node_1 = NULL;
	node_1 = node->children;

	while (node_1 != NULL)
	{
		if (!xmlStrcmp(node_1->name, BAD_CAST "flux"))
		{
			content = xmlNodeGetContent(node_1);
			xmlFree(content);
		}
		node_1 = node_1->next;
	}
}

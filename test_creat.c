#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#include <string.h>



int main(void)
{
	char *string2 = NULL;
	cJSON *name = NULL;
	cJSON *value = NULL;

	/* 创建一个对象 */
    cJSON *cj = cJSON_CreateObject();
    if (cj == NULL)
    {
        goto end;
    }

	/* 创建一个字符串 */
    value = cJSON_CreateNumber(100);
    if (value == NULL)
    {
        goto end;
    }
    /* 将字符串添加到对象中 */
    /* after creation was successful, immediately add it to the cj,
     * thereby transfering ownership of the pointer to it */
    cJSON_AddItemToObject(cj, "battery", value);
	
	name = cJSON_CreateString("data");
    if (name == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(cj, "time", name);
	
	name = cJSON_CreateString("15633162026");
    if (name == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(cj, "sim", name);
	
	value = cJSON_CreateNumber(1);
    if (value == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(cj, "network", value);
	
	value = cJSON_CreateNumber(80);
    if (value == NULL)
    {
        goto end;
    }
    cJSON_AddItemToObject(cj, "signal", value);
	
	
	/* 转换成 JSON 格式的字符串 */
    string2 = cJSON_Print(cj);
    if (string2 == NULL)
    {
        fprintf(stderr, "Failed to print cj.\n");
    }
	
	printf("%s", string2);
	
	free(string2);
	cJSON_Delete(cj);
	
	
	
	
	
	printf("\r\n***************************************************\r\n");
	char *string5 = NULL;
	cJSON *compareList = NULL;
	cJSON *list = NULL;
	cJSON *arrayobject = NULL;
	int index = 0;
	
	cj = cJSON_CreateObject();
    if (cj == NULL)
    {
        goto end;
    }
	
	/* 创建一个数组 */
    compareList = cJSON_CreateArray();
    if (compareList == NULL)
    {
        goto end;
    }
	
    /* 将数组添加到对象中 */
    cJSON_AddItemToObject(cj, "comparecompareList", compareList);

    for (index = 0; index < 5; ++index)
    {
        arrayobject = cJSON_CreateObject();
        if (arrayobject == NULL)
        {
            goto end;
        }
        /* 将对象添加到数组中 */
        cJSON_AddItemToArray(compareList, arrayobject);
		
		value = cJSON_CreateString("date");
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "time", value);
		
        value = cJSON_CreateNumber(120.8);
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "lat", value);
		
        value = cJSON_CreateNumber(70.2);
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "lng", value);
    }

	
	/* 创建一个数组 */
    list = cJSON_CreateArray();
    if (list == NULL)
    {
        goto end;
    }
	
    /* 将数组添加到对象中 */
    cJSON_AddItemToObject(cj, "list", list);

    for (index = 0; index < 5; ++index)
    {
        arrayobject = cJSON_CreateObject();
        if (arrayobject == NULL)
        {
            goto end;
        }
        /* 将对象添加到数组中 */
        cJSON_AddItemToArray(list, arrayobject);
		
		value = cJSON_CreateString("date");
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "time", value);
		
        value = cJSON_CreateNumber(120.8);
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "lat", value);
		
        value = cJSON_CreateNumber(70.2);
        if (value == NULL)
        {
            goto end;
        }
        cJSON_AddItemToObject(arrayobject, "lng", value);
    }
	
	
	/* 转换成 JSON 格式的字符串 */
    string5 = cJSON_Print(cj);
    if (string5 == NULL)
    {
        fprintf(stderr, "Failed to print cj.\n");
    }
	
	
	printf("%s", string5);
	
	free(string5);
	cJSON_Delete(cj);
	
	
	return 0;
	
	
	
	


end:
	/* 释放对象 */
    cJSON_Delete(cj);
    return -1;


}
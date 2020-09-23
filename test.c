#include <stdio.h>
#include <stdlib.h>
#include "cJSON.h"

#include <string.h>



int main(void)
{
	char *Output2 = "{\"state\":1}";

	//从缓冲区中解析出JSON结构
	cJSON * cj= NULL;
	cJSON * item = NULL;
	cJSON * object = NULL;
	cJSON * arrayItem = NULL;
	
	
	cj = cJSON_Parse(Output2);
	if(!cj)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
        return -1 ;
    }

    item = cJSON_GetObjectItem(cj,"state");
    if(item == NULL)
    {
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());  
        cJSON_Delete(cj);
        return -1;
    }
	printf("%d \n",item->valueint);

	const char *Output1 = "{\"state\":1,\"list\":[{\"cmd\":\"device\"},{\"cmd\":\"resetfingerprint\"}]}";
	
	cj = cJSON_Parse(Output1);
	if(!cj)
    {
        printf("Error before: [%s]\n",cJSON_GetErrorPtr());
        return -1 ;
    }
	
    item = cJSON_GetObjectItem(cj,"state");
    if(item == NULL)
    {
		printf("Error before: [%s]\n",cJSON_GetErrorPtr());  
        cJSON_Delete(cj);
        return -1;
    }
	printf("%d \n",item->valueint);
	
	arrayItem = cJSON_GetObjectItem(cj,"list");
    if(!arrayItem)
    {
        printf("cjson_parse failed \n");
        return -1 ;
    }
	int size=cJSON_GetArraySize(arrayItem);  
	for(int i=0;i<size;i++)
	{
		object=cJSON_GetArrayItem(arrayItem,i);
		item=cJSON_GetObjectItem(object,"cmd");
		if(item!=NULL)  
		{  
			printf("cJSON_GetObjectItem: type=%d, string is %s, value is %s\n",item->type,item->string,item->valuestring);   
		}
	}
	
	
    cJSON_Delete(cj);
	

}
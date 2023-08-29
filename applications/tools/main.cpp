#include "json/json.h" 
#include <iostream>
#include <fstream>

using namespace std;

void PhraseFromString()
{
	const char* str = "{\"uploadid\": \"UP000000\",\"code\": 100,\"msg\": \"\",\"files\": \"\"}";  

    Json::Reader reader;  
    Json::Value root;  
    if (reader.parse(str, root))  								// reader将Json字符串解析到root，root将包含Json里所有子元素  
    {  
        std::string upload_id = root["uploadid"].asString();  	// 访问节点，upload_id = "UP000000"  
        int code = root["code"].asInt();    					// 访问节点，code = 100 
		std::string msg = root["msg"].asString(); 
		std::string files = root["files"].asString(); 
		cout<<"upload_id["<<upload_id<<"]"<<endl;
		cout<<"code["<<code<<"]"<<endl;
		cout<<"msg["<<msg<<"]"<<endl;
		cout<<"files["<<files<<"]"<<endl;
    }
}


void toString()
{
	Json::Value root;
    Json::Value arrayObj;
    Json::Value item;
    for (int i=0; i<10; i++)
    {
		item["key"]=i;
		arrayObj.append(item);
    }

    root["key1"] = "value1";
    root["key2"] = "value2";
    root["array"] = arrayObj;
	root["value1"] = 10;
    root.toStyledString();
    std::string out = root.toStyledString();
	ofstream outfile("tostring.json",ofstream::out);
	outfile.write(out.c_str(),out.length());
}

void readFile()
{
	ifstream is("tostring.json", ios::binary);
	
	if (!is.is_open())
    {
        cout << "open json file failed." << endl;
        return;
    }
    
    Json::Reader reader;
    Json::Value root;
	
	int nRole;
	string key1,key2,array;
	if (reader.parse(is, root))
    {
        nRole = root["value1"].asInt();
        key1 = root["key1"].asString();
		key2 = root["key2"].asString();
        //array = root["array"].asString();
    }

	cout<<"nRole["<<nRole<<"]"<<endl;
	cout<<"key1["<<key1<<"]"<<endl;
	cout<<"key2["<<key2<<"]"<<endl;
	//cout<<"array["<<array<<"]"<<endl;
	is.close();
}


int main()
{
	//PhraseFromString();	
	toString();
	
	readFile();
}
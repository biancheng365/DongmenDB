//
// Created by sam on 2018/11/15.
//

#ifndef DONGMENDB_JOIN_H
#define DONGMENDB_JOIN_H

#include <physicalplan/Scan.h>

/*笛卡尔积操作实现*/
class Join : public Scan {
    public:
    Scan* scan1;
    Scan* scan2;
    Expression *cond;

    Join(Scan* scan1, Scan* scan2) : scan1(scan1), scan2(scan2){};

    int beforeFirst();

    int next();

    int close();

    variant* getValueByIndex(int index);

    int getIntByIndex(int index);

    string getStringByIndex(int index);

    int getInt(string tableName, string fieldName);

    variant* getValue(string fieldName);

    string getString(string tableName, string fieldName);

    int hasField(string tableName, string fieldName);

    FieldInfo *getField(string tableName, string fieldName);

    vector<char*> getFieldsName(string tableName);

    int setInt(string tableName, string fieldName, int value);

    int setString(string tableName, string fieldName, string value);

    int deleteRecord();

    int insertRecord();

    int getRID(RecordID *recordID);

    int moveTo(RecordID *recordID);
};
#endif //DONGMENDB_JOIN_H

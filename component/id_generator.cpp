#include <id_generator.h>

#define GEN_ID(id, curID) ((UInt64(id) << 56) + (UInt64(curID)))

void IDGenerator::DBFieldRegister()
{
    ObjAndDBMapping("cur_id", _curID);
}

UInt64 IDGenerator::GenerateID()
{
    UInt64 id = GetID();
    id = GEN_ID(id, _curID);
    ++_curID;
    SyncDataToDB("glob_id", nullptr);
    return id;
}

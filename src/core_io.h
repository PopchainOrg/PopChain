// Copyright (c) 2017-2018 The Popchain Core Developers

#ifndef BITCOIN_CORE_IO_H
#define BITCOIN_CORE_IO_H

#include <string>
#include <vector>

class CBlock;
class CScript;
class uint256;
class UniValue;
class CTransaction;

// core_read.cpp
extern CScript ParseScript(const std::string& s);
extern std::string ScriptToAsmStr(const CScript& script, const bool fAttemptSighashDecode = false);
extern bool DecodeHexTx(CTransaction& tx, const std::string& strHexTx);
extern bool DecodeHexBlk(CBlock&, const std::string& strHexBlk);
extern uint256 ParseHashUV(const UniValue& v, const std::string& strName);
extern uint256 ParseHashStr(const std::string&, const std::string& strName);
extern std::vector<unsigned char> ParseHexUV(const UniValue& v, const std::string& strName);

// core_write.cpp
extern std::string FormatScript(const CScript& script);
extern std::string EncodeHexTx(const CTransaction& tx);
extern void TxToUniv(const CTransaction& tx, const uint256& hashBlock, UniValue& entry);
extern void ScriptPubKeyToUniv(const CScript& scriptPubKey, UniValue& out, bool fIncludeHex);

#endif // BITCOIN_CORE_IO_H

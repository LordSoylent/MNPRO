// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017 The MNPRO developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "chainparams.h"
#include "bignum.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0, uint256("0x000005bb4206f97d00dd73fcc99243825eea703e1f170e10bbdf0dd2933325c5"))
	(2, uint256("0x216d87c45867a0907c466ae137fb755ca43478de248411774076f3e599b2d4e4"))
	(1000, uint256("0x0000014f6db585b8219880a79db41ff1d6e7b5383384aaa6e7858e4cde5d3c79"))
	(4000, uint256("0x745a7fb30b5a8985e9ec7bd4a0b88d9cf6b121da6352ad55bb85c8f58cf61d09"))
	(7000, uint256("0x198e4728f0ccd853ffbfbd7a7797a1c903320cf13f6c2385b126edd0336b13c7"))
	(10000, uint256("0xe54729c00d43073a0ac94ad39cdb1c607bc968227f2a9a24d69edbee391df903"))
	(13500, uint256("0xb6790ef9f660b52a823e82453b73f88fcc173d1c436a99a0900bedf8707d36af"))
	(17800, uint256("0xed80e004469de6a9b74188523efa235172221d6960dacae5ec53c51aa97670aa"))
	(23000, uint256("0x4ba7460a703f04c68dc9d3bf17f198d2ae594a7be73f01bde16e44d96361cb51"))
	(27600, uint256("0x0675d936ad73138d9f2b7d726ac8f7ff3d18f34df76a7a74d8295df987d23228"))
	(31000, uint256("0x77288ae6589398cc744ec91ef2f0f6531906cbfe8cdaa16de49d8ea22f7bce8d"))
	(36000, uint256("0x0927f0f9687dc7f3b8620d2dd2f9124c994186447d32075ab10c9b49314dfcda"))
	(38500, uint256("0xfedfad0393323abf54602011fe93c6a689441643ac46be94ce8ef99dbe808f07"))
	(40764, uint256("0x7d119509ac1b2e827104365d532f386b1605b4412a497a3adc8e5cd39ca60386"));
	

static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
	1546300800, // * UNIX timestamp of last checkpoint block
    0,          // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1740710,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0xd4;
        pchMessageStart[1] = 0x9e;
        pchMessageStart[2] = 0xd3;
        pchMessageStart[3] = 0xad;
        vAlertPubKey = ParseHex("041e2029aed291046d4c7716c1f0698f9396aa7cd9a95ae1e6a463b8a36b6be7ee5b5471857edb0bbadd98c652f724988a83ab6791c15481b9757eb3e732c31ed6");
        nDefaultPort = 30229;
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        nSubsidyHalvingInterval = 1050000;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 2 * 60; // MNPRO: 
        nTargetSpacing = 1 * 60;  // MNPRO:  
        nMaturity = 50;
        nMasternodeCountDrift = 20;
	nMaxMoneyOut = 50000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 1000;
        nModifierUpdateBlock = 1; // we use the version 2 for MNPR

        const char* pszTimestamp = "First Time MNPRO is White,merry christmas 25 Desc 2018 and Happy New Year";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 0 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("048bdbd33c6be2ddec0e3a235999ef3224b026fda49a06a74d8d36915b486bd9ebb8e8d88796bf11576c20bc265cd84fd7db794219808260de5ea08972ad714237") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
		genesis.nTime = 1546300800;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 505475;


         
        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000005bb4206f97d00dd73fcc99243825eea703e1f170e10bbdf0dd2933325c5")); 
        assert(genesis.hashMerkleRoot == uint256("0x59478efc3b9e769017a94de77b28d390f43d29f46b6f9e946f7f1ec74967cf6c")); 

  



        // DNS Seeding

		vSeeds.push_back(CDNSSeedData("95.179.131.223", "95.179.131.223"));
		vSeeds.push_back(CDNSSeedData("217.69.9.93", "217.69.9.93"));
		vSeeds.push_back(CDNSSeedData("104.238.177.207", "104.238.177.207"));
		vSeeds.push_back(CDNSSeedData("209.250.243.131", "209.250.243.131"));         // Single node address
		vSeeds.push_back(CDNSSeedData("209.250.241.176", "209.250.241.176"));         // Single node address
		vSeeds.push_back(CDNSSeedData("45.77.239.108", "45.77.239.108"));             // Single node address
		vSeeds.push_back(CDNSSeedData("107.191.44.102", "107.191.44.102"));           // Single node address
		vSeeds.push_back(CDNSSeedData("45.32.235.211", "45.32.235.211"));             // Single node address
		vSeeds.push_back(CDNSSeedData("108.61.188.67", "108.61.188.67"));             // Single node address
		vSeeds.push_back(CDNSSeedData("108.61.95.114", "108.61.95.114"));             // Single node address
		vSeeds.push_back(CDNSSeedData("45.77.193.238", "45.77.193.238"));             // Single node address
		vSeeds.push_back(CDNSSeedData("45.32.133.67", "45.32.133.67"));               // Single node address
		vSeeds.push_back(CDNSSeedData("108.160.134.29", "108.160.134.29"));           // Single node address
		vSeeds.push_back(CDNSSeedData("207.148.86.107", " 207.148.86.107"));          // Single node address
		vSeeds.push_back(CDNSSeedData("45.63.114.212", "45.63.114.212"));             // Single node address
		vSeeds.push_back(CDNSSeedData("45.32.22.184", "45.32.22.184"));               // Single node address
		vSeeds.push_back(CDNSSeedData("63.211.111.86", "63.211.111.86"));             // Single node address
		vSeeds.push_back(CDNSSeedData("144.202.70.111", "144.202.70.111"));           // Single node address

        // MNPRO addresses start with 'G'
		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 50);
        // MNPRO script addresses start with '3'
		base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 110);
        // MNPRO private keys start with 'K'
		base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 105);
        // MNPRO BIP32 pubkeys start with 'xpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        // MNPRO BIP32 prvkeys start with 'xprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // MNPRO BIP44 coin type is '222' (0x800000de)
        // BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0xde).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 2;
        strSporkKey = "04a56dbe05bed50b5d1ec673b4b308581984f702e3d0ddb78d681f6f5e33d48eee1c8e069948d19fde1e553ba7db88e38ce31e39d8d7a54b85ad61c8512f40abc3";
        strMasternodePoolDummyAddress = "MAKzgFX8EZt3fwzkPv55Q3sZJauPNdR8DQ";
        nStartMasternodePayments = genesis.nTime + 86400; // 24 hours after genesis creation

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x4a;
        pchMessageStart[1] = 0x2d;
        pchMessageStart[2] = 0x32;
        pchMessageStart[3] = 0xbc;
        vAlertPubKey = ParseHex("041b2b4c86273359acac3522471911ed2b303eaab65e8a1de01c06e89f2eab1e55234a4b504f3ce20c6f661f007d0ca15623b4358d9855c7c8ba793a24fa315e22");
        nDefaultPort = 130229;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // MNPRO: 1 day
        nTargetSpacing = 2 * 60;  // MNPRO: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 1;
        nMaxMoneyOut = 21000000 * COIN;

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1516926684;
        genesis.nNonce = 3097091;

        hashGenesisBlock = genesis.GetHash();
        // assert(hashGenesisBlock == uint256("0x00000ec1634e6ee176e84d803713f1dff191abbe0add7a59b817fe56db094b76"));

        vFixedSeeds.clear();
        vSeeds.clear();

      //  vSeeds.push_back(CDNSSeedData("159.89.119.230", "159.89.119.230"));
        
        // Testnet MNPRO addresses start with 'g'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 98);
        // Testnet MNPRO script addresses start with '5' or '6'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 12);
        // Testnet private keys start with 'k'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 108);
        // Testnet MNPRO BIP32 pubkeys start with 'tpub' (Bitcoin defaults)
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xCF).convert_to_container<std::vector<unsigned char> >();
        // Testnet MNPRO BIP32 prvkeys start with 'tprv' (Bitcoin defaults)
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x94).convert_to_container<std::vector<unsigned char> >();
        // Testnet bitcoin green BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = false;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04abb5e65280dda6a113fadfb9877f9c399532245fe1acb61de293ab298034d5084277fab3768774a3b68cbbe5021cc5049ec8c9997a13f64da1afa0bcfb156db1";
        strMasternodePoolDummyAddress = "pbJ4Qad4xc77PpLzMx6rUegAs6aUPWkcUq";
        nStartMasternodePayments = genesis.nTime + 86400; // 24 hours after genesis
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x20;
        pchMessageStart[1] = 0xee;
        pchMessageStart[2] = 0x32;
        pchMessageStart[3] = 0xbc;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // MNPRO: 1 day
        nTargetSpacing = 2 * 60;        // MNPRO: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1516926684;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 0;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 230229;
        // assert(hashGenesisBlock == uint256("0x40d358c1e5dfd45b317f749c5aeeee6842c49fcb9db024e1a52b54ba7f7b1fff"));

        vFixedSeeds.clear(); //! Regtest mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Regtest mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}

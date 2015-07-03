namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class GatewayRule
    {
        public int Enable { get; set; }                    // enable flag 0 - disabled, 1 - enabled
        public string Name { get; set; }                   // public name
        public string RequestSymbol { get; set; }          // symbol\symbols mask\symbols group name
        public string RequestGroup { get; set; }           // group name or group mask
        public string ExeAccountName { get; set; }         // account name
        public int ExeAccountID { get; set; }              // account internal id
        public int ExeMaxDeviation { get; set; }           // max. devation
        public int ExeMaxProfitSlippage { get; set; }      // max profit slippage in pips
        public int ExeMaxProfitSlippageLots { get; set; }  // max profit slippage volume in lots
        public int ExeMaxLosingSlippage { get; set; }      // max losing slippage in pips
        public int ExeMaxLosingSlippageLots { get; set; }  // max losing slippage volume in lots
        public int ExeAccountPos { get; set; }             // account current position
        public int ExeVolumePercent { get; set; }          // coverage percentage
    }
}
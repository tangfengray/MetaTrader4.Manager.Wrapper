namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents gateway rule configuration
    /// </summary>
    public class GatewayRule
    {
        /// <summary>
        /// Enable flag 0 - disabled, 1 - enabled
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Public name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// Symbol\symbols mask\symbols group name
        /// </summary>
        public string RequestSymbol { get; set; }

        /// <summary>
        /// Group name or group mask
        /// </summary>
        public string RequestGroup { get; set; }

        /// <summary>
        /// Account name
        /// </summary>
        public string ExeAccountName { get; set; }

        /// <summary>
        /// Account internal id
        /// </summary>
        public int ExeAccountID { get; set; }

        /// <summary>
        /// Max. devation
        /// </summary>
        public int ExeMaxDeviation { get; set; }

        /// <summary>
        /// Max profit slippage in pips
        /// </summary>
        public int ExeMaxProfitSlippage { get; set; }

        /// <summary>
        /// Max profit slippage volume in lots
        /// </summary>
        public int ExeMaxProfitSlippageLots { get; set; }

        /// <summary>
        /// Max losing slippage in pips
        /// </summary>
        public int ExeMaxLosingSlippage { get; set; }

        /// <summary>
        /// Max losing slippage volume in lots
        /// </summary>
        public int ExeMaxLosingSlippageLots { get; set; }

        /// <summary>
        /// Account current position
        /// </summary>
        public int ExeAccountPos { get; set; }

        /// <summary>
        /// Coverage percentage
        /// </summary>
        public int ExeVolumePercent { get; set; }
    }
}
namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents trade restore result
    /// </summary>
    public class TradeRestoreResult
    {
        /// <summary>
        /// Order
        /// </summary>
        public int Order { get; set; }

        /// <summary>
        /// Restore result:
        /// RET_OK_NONE     - order restored
        /// RET_ERROR       - error restoring order
        /// </summary>
        public byte Res { get; set; }
    }
}

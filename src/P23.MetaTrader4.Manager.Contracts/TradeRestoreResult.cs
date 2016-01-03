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
        /// RET_OK_NONE     -order restored
        /// RET_INVALID_DATA-existent order restored
        /// RET_ERROR       -restoring disabled
        /// </summary>
        public byte Res { get; set; }
    }
}

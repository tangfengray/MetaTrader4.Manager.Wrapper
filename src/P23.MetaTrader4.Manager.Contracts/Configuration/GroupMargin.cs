namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents group margin configuration
    /// </summary>
    public class GroupMargin
    {
        /// <summary>
        /// Security
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Swap size for long positions
        /// </summary>
        public double SwapLong { get; set; }

        /// <summary>
        /// /// <summary>
        /// Swap size for short positions
        /// </summary>
        /// </summary>
        public double SwapShort { get; set; }

        /// <summary>
        /// Margin divider
        /// </summary>
        public double MarginDivider { get; set; }
    }
}
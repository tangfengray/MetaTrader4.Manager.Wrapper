namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents balance difference
    /// </summary>
    public class  BalanceDiff
    {
        /// <summary>
        /// Account number
        /// </summary>
        public int Login { get; set; }
    
        /// <summary>
        /// Difference
        /// </summary>
        public double Diff{ get; set; }
    };
}

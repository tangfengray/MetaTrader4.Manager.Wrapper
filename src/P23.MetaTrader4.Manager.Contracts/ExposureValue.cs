namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents exposure value
    /// </summary>
    public class ExposureValue
    {
        /// <summary>
        /// Currency
        /// </summary>
        public string Currency { get; set; }

        /// <summary>
        /// Clients volume
        /// </summary>
        public double Clients { get; set; }

        /// <summary>
        /// Coverage volume
        /// </summary>
        public double Coverage { get; set; }
    }
}

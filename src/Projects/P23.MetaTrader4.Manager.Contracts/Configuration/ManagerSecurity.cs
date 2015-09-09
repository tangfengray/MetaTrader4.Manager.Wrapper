namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents manager security configuration
    /// </summary>
    public class ManagerSecurity
    {
        /// <summary>
        /// Enable
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Min. lots
        /// </summary>
        public int MinimumLots { get; set; }

        /// <summary>
        /// Max. lots
        /// </summary>
        public int MaximumLots { get; set; }
    };
}
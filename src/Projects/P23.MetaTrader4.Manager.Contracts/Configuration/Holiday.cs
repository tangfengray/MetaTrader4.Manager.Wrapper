namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents holidays configuration
    /// </summary>
    public class Holiday
    {
        /// <summary>
        /// year
        /// </summary>
        public int Year { get; set; }

        /// <summary>
        /// Month
        /// </summary>
        public int Month { get; set; }

        /// <summary>
        /// Day
        /// </summary>
        public int Day { get; set; }

        /// <summary>
        /// Work time-from (minutes)
        /// </summary>
        public int From { get; set; }

        /// <summary>
        /// Work time-to (minutes)
        /// </summary>
        public int To { get; set; }

        /// <summary>
        /// Security name or symbol's group name or "All"
        /// </summary>
        public string Symbol { get; set; }

        /// <summary>
        /// Description
        /// </summary>
        public string Description { get; set; }

        /// <summary>
        /// Enable
        /// </summary>
        public int Enable { get; set; }
    }
}

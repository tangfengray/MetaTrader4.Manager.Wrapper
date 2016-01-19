using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents time configuration
    /// </summary>
    public class Time
    {
        /// <summary>
        /// Server's accessebility (7 days-24 hours, 0-denied, 1-allowed)
        /// </summary>
        public IList<IList<int>> Days { get; set; }
    }
}

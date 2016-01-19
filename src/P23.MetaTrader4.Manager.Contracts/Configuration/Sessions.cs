using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents sessions configuration
    /// </summary>
    public class Sessions
    {
        /// <summary>
        /// Quote sessions
        /// </summary>
        public IList<Session> Quote { get; set; }

        /// <summary>
        /// Trade sessions
        /// </summary>
        public IList<Session> Trade { get; set; }
    }
}

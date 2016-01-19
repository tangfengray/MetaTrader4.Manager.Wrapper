using System.Collections.Generic;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents live updates configuration
    /// </summary>
    public class LiveUpdate
    {
        /// <summary>
        /// Company
        /// </summary>
        public string Company { get; set; }

        /// <summary>
        /// Path to LiveUpdate
        /// </summary>
        public string Path { get; set; }

        /// <summary>
        /// Version
        /// </summary>
        public int Version { get; set; }

        /// <summary>
        /// Build
        /// </summary>
        public int Build { get; set; }

        /// <summary>
        /// Max. simultaneous connections
        /// </summary>
        public int MaxConnect { get; set; }

        /// <summary>
        /// Current connections (read only)
        /// </summary>
        public int Connections { get; set; }

        /// <summary>
        /// Type LIVE_UPDATE_*
        /// </summary>
        public LiveUpdateType Type { get; set; }

        /// <summary>
        /// Enable
        /// </summary>
        public int Enable { get; set; }

        /// <summary>
        /// Files configurations
        /// </summary>
        public IList<FilesConfigurations> Files { get; set; }
    }
}

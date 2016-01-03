using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents performance information
    /// </summary>
    public class PerformanceInfo
    {
        /// <summary>
        /// Time
        /// </summary>
        public UInt32 Ctm { get; set; }

        /// <summary>
        /// Online users
        /// </summary>
        public short Users { get; set; }

        /// <summary>
        /// Processor loading (%)
        /// </summary>
        public short Cpu { get; set; }

        /// <summary>
        /// Free memory (Kb)
        /// </summary>
        public int FreeMem { get; set; }

        /// <summary>
        /// Network activity (Kb/s)
        /// </summary>
        public int Network { get; set; }

        /// <summary>
        /// All open sockets in system
        /// </summary>
        public int Sockets { get; set; }
    };
}

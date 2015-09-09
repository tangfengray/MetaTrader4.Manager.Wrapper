using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents report group request
    /// </summary>
    public class ReportGroupRequest
    {
        /// <summary>
        /// Request group name
        /// </summary>
        public string Name { get; set; }

        /// <summary>
        /// From
        /// </summary>
        public UInt32 From { get; set; }

        /// <summary>
        /// To
        /// </summary>
        public UInt32 To { get; set; }
    }
}

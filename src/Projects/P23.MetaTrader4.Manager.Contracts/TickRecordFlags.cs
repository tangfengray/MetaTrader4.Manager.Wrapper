using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Tick record flag
    /// </summary>
    [Flags]
    public enum TickRecordFlags : sbyte
    {
        /// <summary>
        /// Raw
        /// </summary>
        Raw = 1,
        /// <summary>
        /// Normal
        /// </summary>
        Normal = 2,
        /// <summary>
        /// All
        /// </summary>
        All = Raw | Normal
    }
}
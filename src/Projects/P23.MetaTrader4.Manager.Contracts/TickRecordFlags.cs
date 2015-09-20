using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    [Flags]
    public enum TickRecordFlags : sbyte
    {
        Raw = 1,
        Normal = 2,
        All = Raw | Normal
    }
}
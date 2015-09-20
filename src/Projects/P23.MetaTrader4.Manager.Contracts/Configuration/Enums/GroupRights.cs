using System;

namespace P23.MetaTrader4.Manager.Contracts.Configuration.Enums
{
    [Flags]
    public enum GroupRights
    {
        Email = 1,
        Trailing = 2,
        Advisor = 4,
        Expiration = 8,
        SignalsAll = 16,
        SignalsOwn = 32
    };
}
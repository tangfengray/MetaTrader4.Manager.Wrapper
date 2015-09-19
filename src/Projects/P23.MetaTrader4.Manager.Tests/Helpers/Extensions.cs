using System;

namespace P23.MetaTrader4.Manager.Tests.Helpers
{
    public static class Extensions
    {
        public static uint ToUnixTime(this DateTime input)
        {
            return (uint) input.Subtract(new DateTime(1970, 1, 1)).TotalSeconds;
        }
    }
}
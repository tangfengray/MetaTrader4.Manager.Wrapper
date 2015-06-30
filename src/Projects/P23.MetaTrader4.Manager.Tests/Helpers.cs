using System;

namespace P23.MetaTrader4.Manager.Tests
{
    public static class Helpers
    {
        public static uint ToUnixTime(this DateTime input)
        {
            return (uint) input.Subtract(new DateTime(1970, 1, 1)).TotalSeconds;
        }
    }
}
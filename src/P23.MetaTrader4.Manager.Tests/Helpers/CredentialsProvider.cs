using System;
using System.IO;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests.Helpers
{
    internal static class TestHelpers
    {
        private static readonly Lazy<ConnectionParameters> LazyParameters =
            new Lazy<ConnectionParameters>(() =>
            {
                var config = File.ReadAllText("..\\..\\credentials.config").Split(',');
                return new ConnectionParameters { Login = int.Parse(config[0]), Password = config[1], Server = config[2] };
            });

        public static ClrWrapper CreateWrapper()
        {
            return new ClrWrapper(GetCredentials(),
                @"D:\ProgrammingWorkspace\GitHub\MetaTrader4.Manager.Wrapper\Libraries\mtmanapi\mtmanapi.dll");
        }

        private static ConnectionParameters GetCredentials()
        {
            return LazyParameters.Value;
        }
    }
}
using System;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.ConsoleTestClient
{
    class Program
    {
        static void Main(string[] args)
        {
            using (
                var client =
                    new ClrWrapper(new ConnectionParameters
                    {
                        Login = 0,
                        Password = "",
                        Server = ""
                    }))
            {
                client.UserUpdated += (sender, record) => Console.WriteLine(record.City);
                client.PumpingSwitchEx();
                Console.ReadKey();

            };
        }
    }
}

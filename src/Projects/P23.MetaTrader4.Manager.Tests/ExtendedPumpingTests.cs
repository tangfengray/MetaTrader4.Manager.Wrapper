using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ExtendedPumpingTests
    {
        [TestMethod]
        public void Test()
        {
            using (
                var mt =
                    new ClrWrapper(
                        new ConnectionParameters
                        {
                            Login = 0,
                            Password = "",
                            Server = ""
                        },
                        @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                mt.PumpingStarted += (sender, args) => Debug.WriteLine("started");
                mt.PumpingStopped += (sender, args) => Debug.WriteLine("stopped");
                //mt.TradeAdded += (sender, record) => Debug.WriteLine("added");
                //mt.TradeDeleted += (sender, record) => Debug.WriteLine("deleted");
                //mt.TradeUpdated += (sender, record) => Debug.WriteLine("updated");
                //mt.TradeClosed += (sender, record) => Debug.WriteLine("closed");
                //mt.OnlineUpdated += (sender, record) =>
                //{
                //    var online = mt.OnlineGet();
                //    Debug.WriteLine("{0} {1} {2}", record.Login, online.Count, DateTime.Now);
                //};
                mt.BidAskUpdated += (sender, args) =>
                {
                    foreach (var symbol in new List<string> { "EURUSDhal", "EURUSD", "EURUSDs", "EURUSDins" })
                    {
                        var ticks = mt.TickInfoLast(symbol);
                        foreach (var tickInfo in ticks)
                        {
                            Debug.WriteLine("{2} {1} {0}", tickInfo.Ask, tickInfo.Bid, symbol);
                        }

                    }
                };
                //var r = mt.PumpingSwitch((i =>
                //{
                //    var online = mt.OnlineGet();
                //    Debug.WriteLine("{0} {1} {2}", i, online.Count, DateTime.Now);
                //}));
                mt.SymbolsRefresh();
                mt.SymbolAdd("EURUSDhal");
                mt.SymbolAdd("EURUSD");
                mt.SymbolAdd("EURUSDins");
                mt.SymbolAdd("EURUSDs");
                var s = mt.SymbolsGetAll();
                var s1 = mt.CfgRequestSymbol();
                var r = mt.PumpingSwitchEx();
                Console.WriteLine(r);
                //while (true)
                //{
                //    var ticks = mt.TickInfoLast("EURUSDhal");
                //    foreach (var tickInfo in ticks)
                //    {
                //        Debug.WriteLine("{2} {0} {1}", tickInfo.Bid, tickInfo.Ask, DateTime.Now.ToString("HH:mm:ss fff"));
                //    }
                //    Task.Delay(10).Wait();
                //}
                Thread.Sleep(10000000);
            };
        }
    }
}

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
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
                mt.TradeAdded += (sender, record) => Debug.WriteLine("added");
                mt.TradeDeleted += (sender, record) => Debug.WriteLine("deleted");
                mt.TradeUpdated += (sender, record) => Debug.WriteLine("updated");
                mt.TradeClosed += (sender, record) => Debug.WriteLine("closed");
                var r = mt.PumpingSwitchEx();
                Console.WriteLine(r);
                Thread.Sleep(10000000);
            };
        }
    }
}

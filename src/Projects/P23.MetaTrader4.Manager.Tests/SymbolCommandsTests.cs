using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class SymbolCommandsTests
    {
        [TestMethod]
        public void SymbolInfoGet_Invoke_ExpectedDataReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var autoResetEvent = new AutoResetEvent(false);
                mt.SymbolsRefresh();

                mt.PumpingSwitch((delegate(int i)
                {
                    if (i == 0)
                        autoResetEvent.Set();
                }));

                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));

                var symbol = mt.SymbolInfoGet("EURUSD");

                Assert.IsNotNull(symbol);
            }
        }
    }
}
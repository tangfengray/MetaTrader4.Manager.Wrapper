using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts.Configuration;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ExtendedPumpingTests
    {
        //[TestMethod]
        //public void BidAskUpdated_Invoked_TickSuccesfullyRequested()
        //{
        //    using (var mt = TestHelpers.CreateWrapper())
        //    {
        //        mt.PumpingStarted += (sender, args) => Debug.WriteLine("started");
        //        mt.PumpingStopped += (sender, args) => Debug.WriteLine("stopped");

        //        mt.BidAskUpdated += (sender, args) =>
        //        {
        //            foreach (var symbol in new List<string> { "EURUSD"})
        //            {
        //                var ticks = mt.TickInfoLast(symbol);
        //                foreach (var tickInfo in ticks)
        //                {
        //                    Debug.WriteLine("{2} {1} {0}", tickInfo.Ask, tickInfo.Bid, symbol);
        //                }

        //            }
        //        };

        //        mt.PumpingSwitchEx();
        //        Thread.Sleep(10000000);
        //    }
        //}

        [TestMethod]
        public void PumpingSwitchEx_Invoked_PumpingStartedRised()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                bool pumpingStarted = false;
                mt.PumpingStarted += (sender, args) =>
                {
                    pumpingStarted = true;
                    autoResetEvent.Set();
                };
                
                //Act
                mt.PumpingSwitchEx();

                //Assert
                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStarted);
            }
        }
    }
}

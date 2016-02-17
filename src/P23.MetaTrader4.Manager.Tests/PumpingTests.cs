using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class PumpingTests
    {
        [TestMethod]
        public void SymbolsGroupsGet_Invoked_SymbolGroupsReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var autoResetEvent = new AutoResetEvent(false);
                bool pumpingStarted = false;
                
                mt.PumpingSwitch(i =>
                {
                    if ((PumpingNotificationCodes) i == PumpingNotificationCodes.Start)
                    {
                        autoResetEvent.Set();
                        pumpingStarted = true;
                    }
                });
                
                autoResetEvent.WaitOne(new TimeSpan(0, 0, 10));
                Assert.IsTrue(pumpingStarted, "Pumping was not started");

                //Act
                var groups = mt.SymbolsGroupsGet();

                //Assert
                Assert.IsTrue(groups.Count > 0, "No symbol groups returned");
                Assert.IsFalse(string.IsNullOrEmpty(groups[0].Name));
            }
        }
    }
}
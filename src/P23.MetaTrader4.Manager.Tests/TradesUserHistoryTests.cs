using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class TradesUserHistoryTests
    {
        [TestMethod]
        public void TradesUserHistoryTest1()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Act
                var @from = new DateTimeOffset(2016, 1, 1, 0, 0, 0, 0, TimeSpan.Zero);
                var to = @from.AddYears(1);
                var trades = mt.TradesUserHistory(1000, 0, to);
                
                //Assert
                Assert.IsTrue(trades.Count > 0);
            }
        }
    }
}
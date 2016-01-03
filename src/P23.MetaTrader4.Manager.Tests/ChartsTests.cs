using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ChartsTests
    {
        [TestMethod]
        public void ChartRequest_Invoke_ChartsReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var charts = mt.ChartRequest(new ChartInfo { Start = 0, End = int.MaxValue, Mode = 0, Period = ChartPeriod.H1, Symbol = "EURUSD" }, 0);
                Assert.IsTrue(charts.Count > 0);
            }
        }
    }
}
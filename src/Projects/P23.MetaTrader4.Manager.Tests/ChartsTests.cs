using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ChartsTests
    {
        [TestMethod]
        public void ChartRequest_Invoke_ChartsReturned()
        {
            using (var mt = new ClrWrapper(new ConnectionParameters { Login = 0, Password = "", Server = "" }, @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                var charts = mt.ChartRequest(new ChartInfo {Start = 0, End = int.MaxValue, Mode = 0, Period = 60, Symbol = "EURUSD"}, 0);
                Assert.IsTrue(charts.Count > 0);
            }
        }
    }
}
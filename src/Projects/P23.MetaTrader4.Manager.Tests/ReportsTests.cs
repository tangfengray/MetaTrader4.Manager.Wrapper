using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class ReportsTests
    {
        [TestMethod]
        public void ReportsRequestTest()
        {
            using (var mt = new ClrWrapper(new ConnectionParameters { Login = 0, Password = "", Server = "" }, @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                var logins = new List<int>{1};
                var reports = mt.ReportsRequest(new ReportGroupRequest() { From = 1434974798, Name = "test", To = 1435100000 }, logins);
                Assert.IsNotNull(reports);
            }
        }
    }
}
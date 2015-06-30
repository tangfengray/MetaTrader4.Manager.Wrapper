using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class CfgRequestTests
    {
        [TestMethod]
        public void CfgRequestSymbol()
        {
            using (var mt = new ClrWrapper(new ConnectionParameters { Login = 0, Password = "", Server = "" }, @"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            {
                var configs = mt.CfgRequestSymbol();
                Assert.IsNotNull(configs.Count > 0);
            }
        }
    }
}
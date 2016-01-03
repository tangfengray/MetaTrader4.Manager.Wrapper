using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class CfgRequestTests
    {
        [TestMethod]
        public void CfgRequestSymbol_Invoke_SymbolConfigurationsReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var configs = mt.CfgRequestSymbol();
                Assert.IsTrue(configs.Count > 0);
            }
        }
    }
}
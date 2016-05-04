using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class CfgUpdateTests
    {
        [TestMethod]
        public void CfgUpdateSymbol_Invoke_ReturnsZero()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var config = mt.CfgRequestSymbol().Single(p=>p.Name == "EURUSD");
                config.Trade = TradeMode.Full;

                //Act
                var result = mt.CfgUpdateSymbol(config);

                //Assert
                Assert.AreEqual(0, result);
            }
        }
    }
}

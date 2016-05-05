using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class OrderTests
    {
        [TestMethod]
        public void TradeTransaction_ValidParametersPassed_TransactionExecuted()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var tti = new TradeTransInfo
                {
                    Cmd = TradeCommand.Balance,
                    OrderBy = 1000,
                    Comment = "Test deposit",
                    Price = 1,
                    Type = TradeTransactionType.BrBalance
                };

                //Act
                var result = mt.TradeTransaction(tti);

                //Assert
                Assert.AreEqual(0, result);
                Assert.IsTrue(tti.Order > 1000);
            }
        }
    }
}

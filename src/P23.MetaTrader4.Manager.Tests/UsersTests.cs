using System.Collections.Generic;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using P23.MetaTrader4.Manager.Contracts;
using P23.MetaTrader4.Manager.Tests.Helpers;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class UsersTests
    {
        [TestMethod]
        public void UsersRequest_Invoke_UsersReturned()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                var users = mt.UsersRequest();
                Assert.IsTrue(users.Count > 0);
            }
        }


        [TestMethod]
        public void UserRecordNew_Invoke_UsersCreated()
        {
            using (var mt = TestHelpers.CreateWrapper())
            {
                //Arrange
                var user = new UserRecord
                {
                    Group = "demoforex",
                    Leverage = 100,
                    Name = "Test account",
                    Password = "qwe123",
                    PasswordInvestor = "qwe123"
                };

                //Act
                var result = mt.UserRecordNew(user);
                
                //Assert
                Assert.AreEqual(0, result);
                Assert.IsTrue(user.Login > 1000);
            }
        }
    }
}

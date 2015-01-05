using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace P23.MetaTrader4.Manager.Tests
{
    [TestClass]
    public class InitialTests
    {
        [TestMethod]
        public void ConstructorTest()
        {
            using (var mt = new Manager.ClrWrapper(@"D:\ProgrammingWorkspace\MetaTrader4.Manager.Wrapper\src\Libraries\mtmanapi\mtmanapi.dll"))
            { 

            }
        }
    }
}

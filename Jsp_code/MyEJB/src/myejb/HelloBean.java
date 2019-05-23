package myejb;

import javax.ejb.Stateless;

@Stateless
public class HelloBean implements HelloBeanLocal, HelloBeanRemote {

	public String sayHello(String name) {
		// TODO Auto-generated method stub
		return "Hello" + name;
	}

}

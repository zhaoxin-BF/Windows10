package action;

import com.opensymphony.xwork2.ActionSupport;

import dao.Userinfo;
import dao.UserinfoDAO;

public class AddUserAction extends ActionSupport {

	Userinfo userinfo;
	UserinfoDAO userinfoDAO;
	
	public Userinfo getUserinfo() {
		return userinfo;
	}
	public void setUserinfo(Userinfo userinfo) {
		this.userinfo = userinfo;
	}
	public UserinfoDAO getUserinfoDAO() {
		return userinfoDAO;
	}
	public void setUserinfoDAO(UserinfoDAO userinfoDAO) {
		this.userinfoDAO = userinfoDAO;
	}

	/**
	 * @return
	 */
	public String execute() {
		// TODO Auto-generated method stub
		try{
			userinfoDAO.save(userinfo);
			return SUCCESS;
		}catch(Exception e){
			System.out.println(e);
			return INPUT;
		}

	}
}
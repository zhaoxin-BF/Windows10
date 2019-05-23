package dao;

import javax.persistence.Entity;
import javax.persistence.Table;

/**
 * Userinfo entity. @author MyEclipse Persistence Tools
 */
@Entity
@Table(name = "USERINFO", schema = "CLASSICCARS")
public class Userinfo extends AbstractUserinfo implements java.io.Serializable {

	// Constructors

	/** default constructor */
	public Userinfo() {
	}

	/** minimal constructor */
	public Userinfo(String username) {
		super(username);
	}

	/** full constructor */
	public Userinfo(String username, String password) {
		super(username, password);
	}

}

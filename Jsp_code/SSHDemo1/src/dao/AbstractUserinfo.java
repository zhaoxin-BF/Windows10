package dao;

import javax.persistence.Column;
import javax.persistence.Id;
import javax.persistence.MappedSuperclass;

/**
 * AbstractUserinfo entity provides the base persistence definition of the
 * Userinfo entity. @author MyEclipse Persistence Tools
 */
@MappedSuperclass
public abstract class AbstractUserinfo implements java.io.Serializable {

	// Fields

	private String username;
	private String password;

	// Constructors

	/** default constructor */
	public AbstractUserinfo() {
	}

	/** minimal constructor */
	public AbstractUserinfo(String username) {
		this.username = username;
	}

	/** full constructor */
	public AbstractUserinfo(String username, String password) {
		this.username = username;
		this.password = password;
	}

	// Property accessors
	@Id
	@Column(name = "USERNAME", unique = true, nullable = false, length = 10)
	public String getUsername() {
		return this.username;
	}

	public void setUsername(String username) {
		this.username = username;
	}

	@Column(name = "PASSWORD", length = 10)
	public String getPassword() {
		return this.password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

}
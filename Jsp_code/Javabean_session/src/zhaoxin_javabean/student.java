package zhaoxin_javabean;

public class student {
	private String sno;
	private String sname;
	private String sdno;
	
	public student(){
	}
	
	public student(String sno, String sname, String sdno) {
		super();
		this.sno = sno;
		this.sname = sname;
		this.sdno = sdno;
	}
	public String getSno() {
		return sno;
	}
	public void setSno(String sno) {
		this.sno = sno;
	}
	public String getSname() {
		return sname;
	}
	public void setSname(String sname) {
		this.sname = sname;
	}
	public String getSdno() {
		return sdno;
	}
	public void setSdno(String sdno) {
		this.sdno = sdno;
	}
}

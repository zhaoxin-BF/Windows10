package dao;

import java.util.List;
import java.util.logging.Level;
import javax.ejb.Stateless;
import javax.persistence.EntityManager;
import javax.persistence.PersistenceContext;
import javax.persistence.Query;

/**
 * Facade for entity User.
 * 
 * @see dao.User
 * @author MyEclipse Persistence Tools
 */
@Stateless
public class UserFacade implements UserFacadeLocal, UserFacadeRemote {
	// property constants
	public static final String PASSWORD = "password";

	@PersistenceContext
	private EntityManager entityManager;

	/**
	 * Perform an initial save of a previously unsaved User entity. All
	 * subsequent persist actions of this entity should use the #update()
	 * method.
	 * 
	 * @param entity
	 *            User entity to persist
	 * @throws RuntimeException
	 *             when the operation fails
	 */
	public void save(User entity) {
		LogUtil.log("saving User instance", Level.INFO, null);
		try {
			entityManager.persist(entity);
			LogUtil.log("save successful", Level.INFO, null);
		} catch (RuntimeException re) {
			LogUtil.log("save failed", Level.SEVERE, re);
			throw re;
		}
	}

	/**
	 * Delete a persistent User entity.
	 * 
	 * @param entity
	 *            User entity to delete
	 * @throws RuntimeException
	 *             when the operation fails
	 */
	public void delete(User entity) {
		LogUtil.log("deleting User instance", Level.INFO, null);
		try {
			entity = entityManager.getReference(User.class, entity
					.getUsername());
			entityManager.remove(entity);
			LogUtil.log("delete successful", Level.INFO, null);
		} catch (RuntimeException re) {
			LogUtil.log("delete failed", Level.SEVERE, re);
			throw re;
		}
	}

	/**
	 * Persist a previously saved User entity and return it or a copy of it to
	 * the sender. A copy of the User entity parameter is returned when the JPA
	 * persistence mechanism has not previously been tracking the updated
	 * entity.
	 * 
	 * @param entity
	 *            User entity to update
	 * @return User the persisted User entity instance, may not be the same
	 * @throws RuntimeException
	 *             if the operation fails
	 */
	public User update(User entity) {
		LogUtil.log("updating User instance", Level.INFO, null);
		try {
			User result = entityManager.merge(entity);
			LogUtil.log("update successful", Level.INFO, null);
			return result;
		} catch (RuntimeException re) {
			LogUtil.log("update failed", Level.SEVERE, re);
			throw re;
		}
	}

	public User findById(String id) {
		LogUtil.log("finding User instance with id: " + id, Level.INFO, null);
		try {
			User instance = entityManager.find(User.class, id);
			return instance;
		} catch (RuntimeException re) {
			LogUtil.log("find failed", Level.SEVERE, re);
			throw re;
		}
	}

	/**
	 * Find all User entities with a specific property value.
	 * 
	 * @param propertyName
	 *            the name of the User property to query
	 * @param value
	 *            the property value to match
	 * @return List<User> found by query
	 */
	@SuppressWarnings("unchecked")
	public List<User> findByProperty(String propertyName, final Object value) {
		LogUtil.log("finding User instance with property: " + propertyName
				+ ", value: " + value, Level.INFO, null);
		try {
			final String queryString = "select model from User model where model."
					+ propertyName + "= :propertyValue";
			Query query = entityManager.createQuery(queryString);
			query.setParameter("propertyValue", value);
			return query.getResultList();
		} catch (RuntimeException re) {
			LogUtil.log("find by property name failed", Level.SEVERE, re);
			throw re;
		}
	}

	public List<User> findByPassword(Object password) {
		return findByProperty(PASSWORD, password);
	}

	/**
	 * Find all User entities.
	 * 
	 * @return List<User> all User entities
	 */
	@SuppressWarnings("unchecked")
	public List<User> findAll() {
		LogUtil.log("finding all User instances", Level.INFO, null);
		try {
			final String queryString = "select model from User model";
			Query query = entityManager.createQuery(queryString);
			return query.getResultList();
		} catch (RuntimeException re) {
			LogUtil.log("find all failed", Level.SEVERE, re);
			throw re;
		}
	}

}
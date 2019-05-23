package dao;

import java.util.List;
import javax.ejb.Remote;

/**
 * Remote interface for UserFacade.
 * 
 * @author MyEclipse Persistence Tools
 */
@Remote
public interface UserFacadeRemote {
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
	public void save(User entity);

	/**
	 * Delete a persistent User entity.
	 * 
	 * @param entity
	 *            User entity to delete
	 * @throws RuntimeException
	 *             when the operation fails
	 */
	public void delete(User entity);

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
	public User update(User entity);

	public User findById(String id);

	/**
	 * Find all User entities with a specific property value.
	 * 
	 * @param propertyName
	 *            the name of the User property to query
	 * @param value
	 *            the property value to match
	 * @return List<User> found by query
	 */
	public List<User> findByProperty(String propertyName, Object value);

	public List<User> findByPassword(Object password);

	/**
	 * Find all User entities.
	 * 
	 * @return List<User> all User entities
	 */
	public List<User> findAll();
}
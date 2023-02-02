package main.java.com.api.jpa.repository;

import java.util.UUID;

import org.springframework.data.jpa.repository.JpaRepository;

import main.java.com.api.jpa.model.User;

public interface UserRepository extends JpaRepository<User , UUID>{
    
}

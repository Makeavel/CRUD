package main.java.com.api.jpa.config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfiguration;
import org.springframework.security.config.annotation.web.configuration.WebSecurityCustomizer;

@Configuration
public class SecurityConfig extends WebSecurityConfigurerAdapter{

    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
            .cors()
            .and()
            //.crsf().disable()
            .authorizeRequests()
            .antMatchers("/api/**")
            .permitAll()
            .anyRequest().authenticated()
            .and()
            .sessionManagement();
            //.sessionCreationPolicy(sessionCreationPolicy.STATELESS);
           
    }

@Bean
    public WebSecurityCustomizer webSecurityCustomizer() {
        return (web) -> web.ignoring().antMatchers("/ignore1", "/ignore2");
    }
}
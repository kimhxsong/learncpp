#ifndef FORM_H_
#define FORM_H_

#include <exception>
#include <string>
#include <ostream>

class Bureaucrat;

class Form {
 public:
   class AlreadySignedException : public std::exception {
   public:
    const char *what() const throw() { return "Already Signed"; };
  };

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw() { return "Grade Too High"; };
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw() { return "Grade Too Low"; };
  };

  Form();
  Form(const Form& other);
  Form(const std::string& name, const unsigned int signable_grade,
                                const unsigned int executable_grade);

  ~Form();

  Form& operator=(const Form& other);

  const std::string& getName() const;
  unsigned int getSignableGrade() const;
  unsigned int getExecutableGrade() const;
  const std::string& getTarget() const;
  
  bool isSigned() const;
  void beSigned(const Bureaucrat& signer) const;
  virtual void execute(Bureaucrat const & executor) const = 0;

 protected:
  std::string target_;

 private:
  const std::string name_;
  unsigned int kSignableGrade_;
  unsigned int kExecutableGrade_;
  const bool sign_;
};

std::ostream& operator<<(std::ostream& os, const Form& rhs);

#endif  // FORM_H_

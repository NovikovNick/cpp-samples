#ifndef SAMPLE_PIMPL_MACROS_H
#define SAMPLE_PIMPL_MACROS_H

#define GENERATE_RULE5_DECLARATION(name) \
  name() = default;                      \
  ~name();                               \
  name(name&& other);                    \
  name& operator=(name&& other);         \
  name(const name& other);               \
  name& operator=(const name& other);

#define GENERATE_RULE5_DEFENITION(name)               \
  name::~name() = default;                            \
  name::name(const name& other) = default;            \
  name& name::operator=(const name& other) = default; \
  name::name(name&& other) = default;                 \
  name& name::operator=(name&& other) = default;

#endif  // SAMPLE_PIMPL_MACROS_H
